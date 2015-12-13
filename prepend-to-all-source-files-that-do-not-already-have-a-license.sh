#!/bin/bash

headerfile=`mktemp`
tempfile=`mktemp`
filelist=`grep -iLrs 'Copyright (c) <[[:digit:]]\{4\}> <[^>]\+>' --exclude=*~ src/*.* include/*.*`

if [ -z "$filelist" ] ;then
  
  echo No files need licenses prepended.
  
else
  
  echo The following files need licenses prepended:
  echo $filelist
  
  while :; do

    echo -n "Prepend license to the above files [yN]? "
    read answer

    if echo "$answer" | grep -iq "^y" ;then

      echo -e "/*\n" > $headerfile
      cat license.txt >> $headerfile
      echo -e "\n */\n\n" >> $headerfile

      for f in $filelist; do
        echo prepending license to $f  
        cat $headerfile > $tempfile
        cat $f >> $tempfile
        cp -bf $tempfile $f
      done
      
      echo "All done!"
      break

    elif echo "$answer" | grep -iq "^\(n\|$\)" ;then
      
      echo "No files were modified"
      break
      
    else
      
      echo 
      echo "At least answer 'Y' or 'N'! (or control-C)"
      echo 
      
    fi

  done

fi

rm $tempfile
rm $headerfile


