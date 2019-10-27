#!/bin/bash
norminette srcs/ *.h

read -p "Commit message: " msg

rm a.out

git add .
#git reset HEAD commit.sh test*
git commit -m "$msg"
git push origin master
clear
git status
