#!/bin/bash

set -e -u -o errexit -o errtrace

trap "echo ERROR!" ERR 

function func(){
    echo "Creating error."
    false
}

# trap a func error
func
