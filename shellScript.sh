#fetching all files in the given path recursively
if [ $# != 1 ]
then
	if [ $# == 0 ]
	then
		echo "Provide path as command line argument"
		exit 1
	else
		echo "You should provide only one path"
		exit 1
	fi
fi
files=$(du -a $1 | sort -r)
for item in $files
do
	#checking whether file is in elf format
	if [[ $(file $item) == *'ELF'* ]]
	then
		echo "Filename --> $item"
		echo "Size --> $(du -sh $item | cut -d '	' -f 1)"
	fi
done
