#!/bin/bash
# push_swap comprehensive test suite
# Usage: bash tests.sh

PUSH_SWAP="./push_swap"
CHECKER="./checker"
PASS=0
FAIL=0
WARN=0

GREEN="\033[92m"
RED="\033[91m"
YELLOW="\033[93m"
CYAN="\033[96m"
BOLD="\033[1m"
DIM="\033[2m"
RESET="\033[0m"

pass() { PASS=$((PASS + 1)); echo -e "  ${GREEN}[PASS]${RESET} $1"; }
fail() { FAIL=$((FAIL + 1)); echo -e "  ${RED}[FAIL]${RESET} $1"; }
warn() { WARN=$((WARN + 1)); echo -e "  ${YELLOW}[WARN]${RESET} $1"; }

# Check binaries exist
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}Error: push_swap not found. Run 'make' first.${RESET}"
    exit 1
fi

echo -e "\n${BOLD}${CYAN}═══════════════════════════════════════════${RESET}"
echo -e "${BOLD}${CYAN}       push_swap test suite${RESET}"
echo -e "${BOLD}${CYAN}═══════════════════════════════════════════${RESET}\n"

# ============================================================
echo -e "${BOLD}1. ERROR HANDLING${RESET}"
echo -e "${DIM}───────────────────────────────────────────${RESET}"

# No arguments
OUT=$($PUSH_SWAP 2>&1)
EXIT=$?
if [ -z "$OUT" ] && [ $EXIT -eq 0 ]; then
    pass "No arguments: silent exit 0"
else
    fail "No arguments: expected silent exit 0 (got exit=$EXIT output='$OUT')"
fi

# Non-numeric
OUT=$($PUSH_SWAP a 2>&1)
if echo "$OUT" | grep -q "Error"; then
    pass "Non-numeric 'a': Error"
else
    fail "Non-numeric 'a': expected Error (got '$OUT')"
fi

# Mixed
OUT=$($PUSH_SWAP 1 2 a 2>&1)
if echo "$OUT" | grep -q "Error"; then
    pass "Mixed '1 2 a': Error"
else
    fail "Mixed '1 2 a': expected Error"
fi

# Duplicates
OUT=$($PUSH_SWAP 1 2 1 2>&1)
if echo "$OUT" | grep -q "Error"; then
    pass "Duplicates '1 2 1': Error"
else
    fail "Duplicates '1 2 1': expected Error"
fi

# INT_MAX overflow
OUT=$($PUSH_SWAP 2147483648 2>&1)
if echo "$OUT" | grep -q "Error"; then
    pass "Overflow INT_MAX+1: Error"
else
    fail "Overflow INT_MAX+1: expected Error"
fi

# INT_MIN underflow
OUT=$($PUSH_SWAP -2147483649 2>&1)
if echo "$OUT" | grep -q "Error"; then
    pass "Underflow INT_MIN-1: Error"
else
    fail "Underflow INT_MIN-1: expected Error"
fi

# Plus prefix
OUT=$($PUSH_SWAP +3 +1 +2 2>&1)
if ! echo "$OUT" | grep -q "Error"; then
    pass "Plus prefix '+3 +1 +2': accepted"
else
    fail "Plus prefix '+3 +1 +2': should be accepted"
fi

# Lone minus
OUT=$($PUSH_SWAP - 2>&1)
if echo "$OUT" | grep -q "Error"; then
    pass "Lone minus '-': Error"
else
    fail "Lone minus '-': expected Error"
fi

# Lone plus
OUT=$($PUSH_SWAP + 2>&1)
if echo "$OUT" | grep -q "Error"; then
    pass "Lone plus '+': Error"
else
    fail "Lone plus '+': expected Error"
fi

# Error on stderr
STDOUT=$($PUSH_SWAP a 2>/dev/null)
STDERR=$($PUSH_SWAP a 2>&1 >/dev/null)
if [ -z "$STDOUT" ] && [ -n "$STDERR" ]; then
    pass "Error goes to stderr, not stdout"
else
    fail "Error should go to stderr only (stdout='$STDOUT' stderr='$STDERR')"
fi

# INT_MAX boundary
OUT=$($PUSH_SWAP 2147483647 0 2>&1)
if ! echo "$OUT" | grep -q "Error"; then
    pass "INT_MAX boundary 2147483647: accepted"
else
    fail "INT_MAX boundary: should be accepted"
fi

# INT_MIN boundary
OUT=$($PUSH_SWAP -2147483648 0 2>&1)
if ! echo "$OUT" | grep -q "Error"; then
    pass "INT_MIN boundary -2147483648: accepted"
else
    fail "INT_MIN boundary: should be accepted"
fi

# String argument
OUT=$($PUSH_SWAP "3 1 2" 2>&1)
if ! echo "$OUT" | grep -q "Error"; then
    pass "String argument '3 1 2': accepted"
else
    fail "String argument '3 1 2': should be accepted"
fi

# ============================================================
echo -e "\n${BOLD}2. ALREADY SORTED${RESET}"
echo -e "${DIM}───────────────────────────────────────────${RESET}"

for test in "1" "1 2" "1 2 3" "1 2 3 4 5"; do
    COUNT=$($PUSH_SWAP $test | wc -l)
    if [ "$COUNT" -eq 0 ]; then
        pass "Sorted '$test': 0 ops"
    else
        fail "Sorted '$test': expected 0 ops (got $COUNT)"
    fi
done

# ============================================================
echo -e "\n${BOLD}3. SMALL SORTS (2-5 elements)${RESET}"
echo -e "${DIM}───────────────────────────────────────────${RESET}"

# 2 elements
COUNT=$($PUSH_SWAP 2 1 | wc -l)
if [ "$COUNT" -le 1 ]; then
    pass "2 elements: $COUNT ops (max 1)"
else
    fail "2 elements: $COUNT ops (max 1)"
fi

# 3 elements - all permutations
MAX3=0
for a in 1 2 3; do
    for b in 1 2 3; do
        for c in 1 2 3; do
            if [ "$a" != "$b" ] && [ "$a" != "$c" ] && [ "$b" != "$c" ]; then
                COUNT=$($PUSH_SWAP $a $b $c | wc -l)
                [ "$COUNT" -gt "$MAX3" ] && MAX3=$COUNT
            fi
        done
    done
done
if [ "$MAX3" -le 3 ]; then
    pass "3 elements (all perms): max $MAX3 ops (limit 3)"
else
    fail "3 elements (all perms): max $MAX3 ops (limit 3)"
fi

# 5 elements
MAX5=0
for i in $(seq 1 20); do
    ARG=$(shuf -i 1-100 -n 5 | tr '\n' ' ')
    COUNT=$($PUSH_SWAP $ARG | wc -l)
    [ "$COUNT" -gt "$MAX5" ] && MAX5=$COUNT
done
if [ "$MAX5" -le 12 ]; then
    pass "5 elements (20 runs): max $MAX5 ops (limit 12)"
else
    fail "5 elements (20 runs): max $MAX5 ops (limit 12)"
fi

# ============================================================
echo -e "\n${BOLD}4. CORRECTNESS (with checker)${RESET}"
echo -e "${DIM}───────────────────────────────────────────${RESET}"

if [ ! -f "$CHECKER" ]; then
    warn "Checker not found, skipping correctness tests. Run 'make bonus'."
else
    # Small sizes
    for size in 3 5 10 20; do
        ALL_OK=1
        for i in $(seq 1 10); do
            ARG=$(shuf -i 1-1000 -n $size | tr '\n' ' ')
            RES=$($PUSH_SWAP $ARG | $CHECKER $ARG)
            if [ "$RES" != "OK" ]; then
                ALL_OK=0
                break
            fi
        done
        if [ $ALL_OK -eq 1 ]; then
            pass "Size $size (10 runs): all OK"
        else
            fail "Size $size: checker returned KO"
        fi
    done

    # 100 elements
    ALL_OK=1
    for i in $(seq 1 10); do
        ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
        RES=$($PUSH_SWAP $ARG | $CHECKER $ARG)
        if [ "$RES" != "OK" ]; then
            ALL_OK=0
            break
        fi
    done
    if [ $ALL_OK -eq 1 ]; then
        pass "Size 100 (10 runs): all OK"
    else
        fail "Size 100: checker returned KO"
    fi

    # 500 elements
    ALL_OK=1
    for i in $(seq 1 5); do
        ARG=$(shuf -i 1-50000 -n 500 | tr '\n' ' ')
        RES=$($PUSH_SWAP $ARG | $CHECKER $ARG)
        if [ "$RES" != "OK" ]; then
            ALL_OK=0
            break
        fi
    done
    if [ $ALL_OK -eq 1 ]; then
        pass "Size 500 (5 runs): all OK"
    else
        fail "Size 500: checker returned KO"
    fi
fi

# ============================================================
echo -e "\n${BOLD}5. PERFORMANCE BENCHMARKS${RESET}"
echo -e "${DIM}───────────────────────────────────────────${RESET}"

# 100 elements benchmark
TOTAL=0; MAX=0; MIN=99999
for i in $(seq 1 20); do
    ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' ')
    COUNT=$($PUSH_SWAP $ARG | wc -l)
    TOTAL=$((TOTAL + COUNT))
    [ "$COUNT" -gt "$MAX" ] && MAX=$COUNT
    [ "$COUNT" -lt "$MIN" ] && MIN=$COUNT
done
AVG=$((TOTAL / 20))
echo -e "  ${BOLD}100 elements (20 runs):${RESET}"
echo -e "    avg=$AVG  min=$MIN  max=$MAX"
if [ "$MAX" -lt 700 ]; then
    pass "100 elements: max $MAX < 700 (5/5 points)"
elif [ "$MAX" -lt 900 ]; then
    warn "100 elements: max $MAX < 900 (4/5 points)"
elif [ "$MAX" -lt 1100 ]; then
    warn "100 elements: max $MAX < 1100 (3/5 points)"
else
    fail "100 elements: max $MAX >= 1100"
fi

# 500 elements benchmark
TOTAL=0; MAX=0; MIN=99999
for i in $(seq 1 10); do
    ARG=$(shuf -i 1-50000 -n 500 | tr '\n' ' ')
    COUNT=$($PUSH_SWAP $ARG | wc -l)
    TOTAL=$((TOTAL + COUNT))
    [ "$COUNT" -gt "$MAX" ] && MAX=$COUNT
    [ "$COUNT" -lt "$MIN" ] && MIN=$COUNT
done
AVG=$((TOTAL / 10))
echo -e "  ${BOLD}500 elements (10 runs):${RESET}"
echo -e "    avg=$AVG  min=$MIN  max=$MAX"
if [ "$MAX" -lt 5500 ]; then
    pass "500 elements: max $MAX < 5500 (5/5 points)"
elif [ "$MAX" -lt 7000 ]; then
    warn "500 elements: max $MAX < 7000 (4/5 points)"
elif [ "$MAX" -lt 8500 ]; then
    warn "500 elements: max $MAX < 8500 (3/5 points)"
else
    fail "500 elements: max $MAX >= 8500"
fi

# ============================================================
echo -e "\n${BOLD}6. CHECKER TESTS${RESET}"
echo -e "${DIM}───────────────────────────────────────────${RESET}"

if [ ! -f "$CHECKER" ]; then
    warn "Checker not found, skipping. Run 'make bonus'."
else
    # Invalid operation
    RES=$(echo "invalid" | $CHECKER 3 2 1 2>&1)
    if echo "$RES" | grep -q "Error"; then
        pass "Checker: invalid op -> Error"
    else
        fail "Checker: invalid op should return Error (got '$RES')"
    fi

    # Wrong result
    RES=$(echo "sa" | $CHECKER 1 2 3)
    if [ "$RES" = "KO" ]; then
        pass "Checker: wrong sort -> KO"
    else
        fail "Checker: wrong sort should return KO (got '$RES')"
    fi

    # Correct result
    RES=$(printf "sa\nrra\n" | $CHECKER 3 2 1)
    if [ "$RES" = "OK" ]; then
        pass "Checker: correct sort -> OK"
    else
        fail "Checker: correct sort should return OK (got '$RES')"
    fi

    # Already sorted, no ops
    RES=$(printf "" | $CHECKER 1 2 3)
    if [ "$RES" = "OK" ]; then
        pass "Checker: sorted + no ops -> OK"
    else
        fail "Checker: sorted + no ops should return OK (got '$RES')"
    fi

    # Error handling same as push_swap
    RES=$($CHECKER a 2>&1)
    if echo "$RES" | grep -q "Error"; then
        pass "Checker: non-numeric -> Error"
    else
        fail "Checker: non-numeric should return Error"
    fi

    RES=$($CHECKER 1 1 2>&1)
    if echo "$RES" | grep -q "Error"; then
        pass "Checker: duplicates -> Error"
    else
        fail "Checker: duplicates should return Error"
    fi
fi

# ============================================================
echo -e "\n${BOLD}${CYAN}═══════════════════════════════════════════${RESET}"
echo -e "${BOLD}  Results: ${GREEN}$PASS passed${RESET}  ${RED}$FAIL failed${RESET}  ${YELLOW}$WARN warnings${RESET}"
TOTAL=$((PASS + FAIL))
if [ $FAIL -eq 0 ]; then
    echo -e "${BOLD}${GREEN}  All tests passed!${RESET}"
else
    echo -e "${BOLD}${RED}  $FAIL/$TOTAL tests failed${RESET}"
fi
echo -e "${BOLD}${CYAN}═══════════════════════════════════════════${RESET}\n"

exit $FAIL
