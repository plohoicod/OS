#!/bin/bash

function aw {
    while [ -f num.txt.lock ]; do
        wait;
    done

    ln num.txt num.txt.lock
    #critical condition
    local n=$(tail -n 1 num.txt);
    n=$[n+1];
    echo $n;
    echo $n>>num.txt
    rm num.txt.lock
    wait;
    }
(aw) & sleep 0.01
(aw)
wait
