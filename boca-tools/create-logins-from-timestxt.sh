#!/bin/bash

echo "[user]"

usernumber=2000
i=1
while read ies nome ; do

    login="team$i"
    senha=$(printf %05d $(( $RANDOM % 100000 )))

    echo "usernumber=$usernumber"
    echo "usersitenumber=1"
    echo "usericpcid=1"
    echo "username=$login"
    echo "userfullname=($ies) $nome"
    echo "usertype=team"
    echo "userpassword=$senha"
    echo "userenabled=t"
    echo "usermultilogin=t"

    ((usernumber++))
    ((i++))

    echo

done < times.txt

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
echo "userpassword=147staff741"
echo "userenabled=t"
echo "usermultilogin=t"
echo ""

# two judges
for i in {1..2}; do
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
