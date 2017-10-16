#!/bin/bash

set -Eu  # set -E exports trap to functions

trapfunc() {
    status=$?
    echo "exit status: ${status}"
    if [ $status -eq 1 ]; then
        echo "unbound var!"
    fi
    exit $status
}

trap 'trapfunc' EXIT
# trap 'rc=$?; echo "EXIT (rc: $rc)"; exit $rc' EXIT

function func(){
    unboundvar=$5
    echo "never makes it here."
}

# trap a func exit for unbound var
func
