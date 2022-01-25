#!/bin/sh
# --- T2-COPYRIGHT-NOTE-BEGIN ---
# This copyright note is auto-generated by ./scripts/Create-CopyPatch.
# 
# T2 SDE: misc/archive/adddownload.sh
# Copyright (C) 2004 - 2005 The T2 SDE Project
# 
# More information can be found in the files COPYING and README.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License. A copy of the
# GNU General Public License can be found in the file COPYING.
# --- T2-COPYRIGHT-NOTE-END ---
#

if [ $# -lt 2 ] ; then
	cat <<-EOT
Usage:
$0 packagename Download_1 < Download_2, Download_n >

	EOT
	exit 1
fi

confdir=$( echo package/*/$1 )
package=$1; shift
rep="$( echo $confdir | cut -d'/' -f 2 )"
if [ "$rep" == "*" ]; then
	echo "failed"
	echo -e "\tpackage $package doesn't exist!\n"
	exit
fi

echo -n "Appending downloads to $package.desc ... "
while [ "$1" ]; do
	dl=$1; shift
	file=${dl##*/}
	server=${dl%$file}
	echo [D] 0 $file $server >> $confdir/$package.desc
done

echo "ok"
echo
