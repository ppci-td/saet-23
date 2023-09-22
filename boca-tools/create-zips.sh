#!/bin/bash

LETTERS=ABCDEFGHIJKLMNOPQRSTUVWXYZ

if (( $# != 1 )); then
    echo "Uso: $0 <contest-dir>"
    echo "Ex: $0 ../14o-treino"
    exit 1
fi

CDIR=$1

echo "Removing old zip files..."
rm -f *.zip

# get number of problems
numproblems=$(grep '^\\section\*{' $CDIR/prova.tex | wc -l)
echo "$numproblems problem(s) detected."

# for each problem
for pid in $(seq 0 $(( $numproblems - 1)) ); do

    # problem letter, fullname and shortname
    pl=${LETTERS:$pid:1}
    pfullname=$(grep '^\\section\*{'$pl $CDIR/prova.tex | cut -d' ' -f2- |\
                cut -d'}' -f1)
    pshortname=$(grep '^\\section\*{'$pl  $CDIR/prova.tex -A2 |\
                 grep 'Arquivo: ' | cut -d' ' -f3 | cut -d'.' -f1)

    ptle=$(grep '^\\section\*{'$pl  $CDIR/prova.tex | awk -F'tle=' '{print $2}')

    # create directory
    echo -n "Setting up $pl: $pfullname ($pshortname, ${ptle}s)..."
    cp -r template_problem $pl

    # Problem infos
    echo "basename=$pshortname" > $pl/description/problem.info
    echo "fullname=$pfullname" >> $pl/description/problem.info

    # Add prova.pdf as descfile for problem A only
    rm -f $pl/description/desc.txt
    if [[ "$pl" == "A" ]]; then
        echo "descfile=prova.pdf" >> $pl/description/problem.info
        cp $CDIR/prova.pdf $pl/description/
    fi

    # Load input/output files
    mkdir -p $pl/input
    mkdir -p $pl/output
    numcases=$( ls ${CDIR}/${pshortname}/inout/*.in | wc -l)
    for i in $(seq 0 $(( $numcases - 1 )) ); do
        cp ${CDIR}/${pshortname}/inout/in_${i}.in $pl/input/file${i}
        cp ${CDIR}/${pshortname}/inout/in_${i}.out $pl/output/file${i}
    done

    # Set TLE and other limits
    for lan in c cpp cc java py2 py3; do
        echo "echo $ptle" > $pl/limits/$lan
        echo "echo 1" >> $pl/limits/$lan
        echo "echo 512" >> $pl/limits/$lan
        echo "echo 5120" >> $pl/limits/$lan
        echo "exit 0" >> $pl/limits/$lan
    done

    # Zip it!
    echo -n "Creating zip file..."
    cd $pl
    zip -qr ${pl}.zip *
    mv ${pl}.zip ..
    cd ..

    rm -rf $pl/

    echo "Done!"

done
