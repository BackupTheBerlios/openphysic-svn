#/!usr/bin/env bash

echo "Compose"

#mkdir temp
#mkdir temp/recto
#mkdir temp/verso

#mkdir output

# ./cleanup.sh
rm temp/*

# Cover
# =====
i=1
for file in cover/*.jpg
do
  from=$file
  to=temp/_cover_$(printf "%03d" $i).jpg
  echo "Copy \"$from\" to \"$to\""
  cp "$from" "$to"
  i=$(($i + 1))
done

# Recto
# =====
i=1
for file in recto/*.jpg;
do
  from=$file
  to=temp/$(printf "%03d" $i).jpg
  echo "Copy \"$file\" to \"$to\""
  cp "$file" "$to"
  i=$(($i + 2))
done

# Verso
# =====
#i=300
i=$(($i - 1))
for file in verso/*.jpg;
do
  from=$file
  to=temp/$(printf "%03d" $i).jpg
  echo "Copy \"$file\" to \"$to\""
  cp "$file" "$to"
  i=$(($i - 2))
done

# Back
# ====
i=1
for file in back/*.jpg
do
  from=$file
  to=temp/z_back_$(printf "%03d" $i).jpg
  echo "Copy \"$from\" to \"$to\""
  cp "$from" "$to"
  i=$(($i + 1))
done