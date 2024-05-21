#!/bin/bash

##  Colors
GRN='\033[0;32m'
RED='\033[0;31m'
YEL='\033[1;33m'
NC='\033[0m' # No Color

CFLAGS='-Wall -Wextra -g -iquote./includes/'

TOTAL=0
GOOD='🥵'
SUCCESS=0
GOOD_LOG="tests/.leru.log"
echo -n "" > ${GOOD_LOG}
BAD='💀'
FAILURE=0
BAD_LOG="tests/.lematch.log"
echo -n "" > ${BAD_LOG}
VG_LOG="tests/.vglog"

#LEAK
function check_leak() {
    STRING=$(cat $VG_LOG | grep "total heap usage:")
    allocs=$(echo "$STRING" | grep -oE '[0-9]+ allocs' | awk '{print $1}')
    frees=$(echo "$STRING" | grep -oE '[0-9]+ frees' | awk '{print $1}')

    if [ "$allocs" -eq "$frees" ]
    then
        return 0
    fi
    return 1
}
#   $1  TEST NAME
#   $2  TEST_SOURCE
function tests_run() {
    BIN=".tmp.out"
    RELEVANT_LOG="-"
    RELEVANT_COLOR="-"
    ISLEAK=0
    VG_LOG="tests/log/$1_valgrind.log"
    
    echo -e "${YEL} Testing $1... ${NC}"
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
    gcc $2 ${CFLAGS} -o ${BIN} -L. -llinked
    valgrind -s --leak-check=full --log-file="$VG_LOG" ./${BIN}
    if [ $? -eq 0 ]
    then
        RELEVANT_LOG=${GOOD_LOG}
        RELEVANT_COLOR=${GRN}
        SUCCESS=$((1 + $SUCCESS))
        check_leak
        ISLEAK=$?
    else
        RELEVANT_LOG=${BAD_LOG}
        RELEVANT_COLOR=${RED}
        FAILURE=$((1 + $FAILURE))
    fi
    if [ $ISLEAK -eq 0 ]
    then
        echo -e "${RELEVANT_COLOR}   -$1${NC}" >> ${RELEVANT_LOG}
    else
        echo -e "${RELEVANT_COLOR}   -$1 \e[3m(Memory leak)\e[0m ${NC}" >> ${RELEVANT_LOG}
    fi
    TOTAL=$((1 + $TOTAL))
    rm ${BIN} || true
}
#RESULTS
function print_result() {
    echo -e "${YEL}\nResults:${NC}"

    #Success
    if (( ${SUCCESS} > 0 ))
    then
        echo -e "${GRN}[${GOOD}]Success:\t${SUCCESS}/${TOTAL}"
        cat ${GOOD_LOG}
        echo -ne "${NC}"
    fi

    #Failure
    if (( ${FAILURE} > 0 ))
    then
        echo -e "\n${RED}[${BAD}]Failure:\t${FAILURE}/${TOTAL}"
        cat ${BAD_LOG}
        echo -n -e "${NC}"
    fi
    echo -e "${NC}"
    rm ${GOOD_LOG} || true
    rm ${BAD_LOG} || true
    return
}

tests_run "Create+Destroy" "tests/create_t.c"
tests_run "Node Management" "tests/add_node_t.c"
#tests_run "Perfect" "tests/perfect_t.c"
#tests_run "Leak" "tests/leak_t.c"

print_result