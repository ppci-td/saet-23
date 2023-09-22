#!/bin/bash

if (( $# != 1 )); then
    echo "Uso: $0 <number of generic teams>"
    echo "For generic teams only."
    exit 1
fi

teams=$1

echo "[user]"

usernumber=2000
for i in $(seq 1 $teams); do

    senha=$(printf %04d $(( $RANDOM % 10000 )) )

	echo "usernumber=$usernumber"
	echo "usersitenumber=1"
	echo "usericpcid=1"
	echo "username=team$i"
	echo "userfullname=team$i"
	echo "usertype=team"
	echo "userpassword=$senha"
	echo "userenabled=t"
    echo "usermultilogin=t"

	((usernumber++))
	echo ""
done


# non-teams users
usernumber=3000

# one staff
echo "usernumber=$usernumber"
((usernumber++))
echo "usersitenumber=1"
echo "usericpcid=1"
echo "username=staff1"
echo "userfullname=Staff UTFPR"
echo "usertype=staff"
echo "userpassword=123staff596"
echo "userenabled=t"
echo "usermultilogin=t"
echo ""

# six judges
for i in {1..6}; do
	echo "usernumber=$usernumber"
	((usernumber++))
	echo "usersitenumber=1"
	echo "usericpcid=1"
	echo "username=juiz$i"
	echo "userfullname=Juiz $i"
	echo "usertype=judge"
	echo "userpassword=147juiz741"
	echo "userenabled=t"
    echo "usermultilogin=t"
	echo ""
done

# score user
echo "usernumber=$usernumber"
((usernumber++))
echo "usersitenumber=1"
echo "usericpcid=1"
echo "username=score"
echo "userfullname=score"
echo "usertype=score"
echo "userpassword=score"
echo "userenabled=t"
echo "usermultilogin=t"
echo ""
