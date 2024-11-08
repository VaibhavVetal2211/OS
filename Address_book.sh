#!/bin/bash

PASSWORD="2211"

create_address_book() {
    if [ ! -e "student.txt" ]; then
        touch "student.txt"
        echo "File created"
    fi
}

view_address_book() {
    # Prompt the user to enter the password
    echo -n "Enter password to view the address book: "
    read -s input_password
    echo  # For a new line after silent input

    # Check if the entered password is correct
    if [ "$input_password" != "$PASSWORD" ]; then
        echo "Incorrect password. Access denied."
        return
    fi

    echo "Password accepted. Access granted."

    if [ ! -e "student.txt" ]; then
        echo "File does not exist"
        return
    fi

    if [ ! -s "student.txt" ]; then
        echo "File is empty"
        return
    fi

    sort student.txt
}

insert_record() {
    if [ ! -e "student.txt" ]; then
        echo "File does not exist"
        return
    fi

    echo -n "Enter name: "
    read name

    # Loop until a valid roll number is provided
    while true; do
        echo -n "Enter Roll no. (5 digits): "
        read rollno

        # Roll number validation (should be 5 digits)
        if [[ $rollno =~ ^[0-9]{5}$ ]]; then
            break  # Valid input; exit the loop
        else
            echo "Invalid roll no. format. Please enter exactly 5 digits."
        fi
    done

    echo -n "Enter Batch: "
    read batch

    echo "$name|$rollno|$batch" >> "student.txt"
    echo "Record Inserted"
}


delete_record() {
    if [ ! -e "student.txt" ]; then
        echo "File does not exist"
        return
    fi

    echo -n "Enter the roll number of the record to be deleted: "
    read rollno

    if [ -z "$(grep -i $rollno student.txt)" ]; then
        echo "Record not found"
    else
        sed -i "/$rollno/d" student.txt
        echo "Record deleted"
    fi
}

modify_record() {
    if [ ! -e "student.txt" ]; then
        echo "File does not exist"
        return
    fi

    echo -n "Enter the roll number of the record to be modified: "
    read rollno

    if [ -z "$(grep -i $rollno student.txt)" ]; then
        echo "Record not found"
        return
    fi

    # Extract current values
    old_record=$(grep -i $rollno student.txt)
    old_name=$(echo "$old_record" | cut -d '|' -f 1)
    old_batch=$(echo "$old_record" | cut -d '|' -f 3)

    # Delete the old record
    sed -i "/$rollno/d" student.txt

    # Display modification menu
    echo "Select which attribute to modify:"
    echo "1. Name"
    echo "2. Roll No."
    echo "3. Batch"
    echo "4. Modify All"
    echo "5. Cancel"

    read -p "Enter your choice: " choice

    new_name=$old_name
    new_rollno=$rollno
    new_batch=$old_batch

    case $choice in
        1) 
            echo -n "Enter new name: "
            read new_name
            ;;
        2) 
            while true; do
                echo -n "Enter new Roll No. (5 digits): "
                read new_rollno
                if [[ $new_rollno =~ ^[0-9]{5}$ ]]; then
                    break
                else
                    echo "Invalid roll no. format. Please enter exactly 5 digits."
                fi
            done
            ;;
        3) 
            echo -n "Enter new batch: "
            read new_batch
            ;;
        4) 
            echo -n "Enter new name: "
            read new_name
            while true; do
                echo -n "Enter new Roll No. (5 digits): "
                read new_rollno
                if [[ $new_rollno =~ ^[0-9]{5}$ ]]; then
                    break
                else
                    echo "Invalid roll no. format. Please enter exactly 5 digits."
                fi
            done
            echo -n "Enter new batch: "
            read new_batch
            ;;
        5) 
            echo "Modification canceled."
            echo "$old_record" >> student.txt  # Re-insert the old record if canceled
            return
            ;;
        *) 
            echo "Invalid choice. No changes made."
            echo "$old_record" >> student.txt  # Re-insert the old record
            return
            ;;
    esac

    # Add the modified record back to the file
    echo "$new_name|$new_rollno|$new_batch" >> student.txt
    echo "Record modified successfully."
}

main() {
    while true; do
        echo -e "\n  Menu:"
        echo "1. Create database"
        echo "2. View database"
        echo "3. Insert Record"
        echo "4. Delete Record"
        echo "5. Modify Record"
        echo "6. Exit"
        echo -e "\n"

        read -p "Enter Choice: " choice

        case $choice in
            1) create_address_book ;;
            2) view_address_book ;;
            3) insert_record ;;
            4) delete_record ;;
            5) modify_record ;;
            6) exit ;;
            *) echo "Invalid Choice" ;;
        esac
    done
}

main

