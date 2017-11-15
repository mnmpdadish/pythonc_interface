#!/bin/sh
#bash code to create tar.gz archive for release
#use with command:
#$ ./release.sh

cd ..
tar -cvzf pythonc_interface.tar.gz pythonc_interface --exclude-vcs-ignores --exclude-vcs --exclude='release.sh'
mv pythonc_interface.tar.gz pythonc_interface/.

#options used:
#--exclude-vcs-ignores:  consider the .hgignore or .gitignore file to ignore files in the tar
#--exclude-vcs:          do not include the .hg and/or .git directories
#--exclude='release.sh': do not include this file

