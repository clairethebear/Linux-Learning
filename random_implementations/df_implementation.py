#!/usr/bin/python
""" Python script that replicates the df binary used in Linux"""
import sys
import os


def get_filesystems():
    """ Get the filesystems currently mounted on the system
    Returns: dict, dictionary of the name of the filesystem and location
    """
    # Open the file /proc/mounts for reading
    f = open('/proc/mounts', 'r+')
    list_of_filesystems = []
    # Seperate the file by lines and add them to a list
    for new_line in f:
        list_of_filesystems.append(new_line)

    list_of_filesystem_locations = []
    # Create a dictionary to store the results
    result_dict = {}
    # seperate the line by whitespace and organize information
    for filesystem in list_of_filesystems:
        split_by_whitespace = filesystem.split()
        # Add the results to a dictionary
        result_dict[split_by_whitespace[0]] = split_by_whitespace[1]
    return result_dict


def get_filesize_block():
    """ Get the details of the file system by using slicing and statvfs
    Returns: dict, dictionary of the block size, free blocks, inodes count
    """
    file_systems = get_filesystems()
    # Create a dictionary for the results
    result = dict()
    for filesystem_location in file_systems.iteritems():
        stat_of_fs = os.statvfs(filesystem_location[1])
        result[filesystem_location[0]] = [filesystem_location[1], stat_of_fs.f_bsize, stat_of_fs.f_bfree, stat_of_fs.f_files]
    return result


def print_results():
    """Print the results to stdout
        """
        # Retrieve the results from the get_filesize_block function
        result_set = get_filesize_block()
        # Iterate through the dictionary and print the results
        for results in result_set:
            # Print the key of the dictionary
            print results
            for values in result_set[results]:
                # Print the values of the dictionary
                print values

# Call print results
print_results()
