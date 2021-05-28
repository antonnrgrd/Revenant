#!/bin/bash

if [ "$#" -le 1 ]; then
    echo "Err: provide at least one filename and one project name"
    exit 1
fi

echo "${@: -1}"

argc=$#
argv="$@"
i=1
echo "${!i}"
while [ "${!i}" != "${@: -1}" ]; do 
    echo  "/*This file is part of ${@: -1}.

${@: -1} is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

${@: -1}  is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ${@: -1}.  If not, see <https://www.gnu.org/licenses/>. */" >> "${!i}"
    i=$((i+1))
done

    
