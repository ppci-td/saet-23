#! /bin/env python3

import sys

KEYS = ["username", "userfullname", "usertype", "userpassword"]
BOCA_URL = "http://maratona.td.utfpr.edu.br/boca"

if len(sys.argv) < 2:
    print("Usage: %s TEAMS_FILE" % (sys.argv[0]))
    sys.exit(1)

teams = open(sys.argv[1], "r")

current = {}
for line in teams:
    line = line.split("=", 1)

    if line[0] in KEYS:
        current[line[0]] = line[1].strip("\n\r")

    if len(current) == len(KEYS):
        if current["usertype"] == "team":
            print("%s\nlogin: %s senha: %s\n%s\n\n" % (current["userfullname"],
                    current["username"], current["userpassword"], BOCA_URL))
        current = {}

teams.close()
