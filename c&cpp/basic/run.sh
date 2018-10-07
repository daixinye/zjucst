name=$1

ls $name.c &> /dev/null
if [[ $? == 0 ]]; then
    gcc $name.c -o $name
    if [[ $? > 0 ]]; then
        exit
    fi
    ./$name
    exit
fi

ls $name.cpp &> /dev/null
if [[ $? == 0 ]]; then
    g++ $name.cpp -o $name
    if [[ $? > 0 ]]; then
        exit
    fi
    ./$name
    exit
fi
