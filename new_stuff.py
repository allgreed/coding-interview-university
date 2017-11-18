#!/usr/bin/python3
# use inside chapter folders (eq. data_structures)
# takes 1 argument: assignment_name [singular](eg. hash_table)

import sys, os, pathlib
from distutils.dir_util import copy_tree
import itertools
import fileinput

assignment_name = sys.argv[1]
assignment_dir = os.getcwd()
script_dir = os.path.dirname(os.path.realpath(__file__))

assignemnt_name_plural = "{}s".format(assignment_name)
assignment_name_uppercase = assignment_name.upper()
assignment_name_class_name = assignment_name.title().replace("_", "")

replacemenets = { "$ASSIGNMENT_NAME_PLURAL$": assignemnt_name_plural, "$ASSIGNMENT_NAME$": assignment_name, "$ASSIGNEMNT_NAME_UPERCASE$": assignment_name_uppercase, "$ASSIGNMENT_NAME_CLASS_NAME$": assignment_name_class_name }
assignemnt_path = "{}/{}".format(assignment_dir, assignemnt_name_plural)
template_path = "{}/course/templates".format(script_dir)

def list_template_files_paths():
    filelists = [["{}/{}".format(root, file) for file in files]
        for root, dirs, files in os.walk(assignemnt_path)]

    return list(itertools.chain.from_iterable(filelists))

def replace_in_line(line):
    retline = line
    for key, value in replacemenets.items():
        retline = retline.replace(key, value)
    return retline

def main():
    pathlib.Path(assignemnt_path).mkdir(parents=True, exist_ok=True)
    copy_tree(template_path, assignemnt_path)
    files = list_template_files_paths()

    with fileinput.FileInput(files=files, inplace=True) as file:
        for line in file:
            print(replace_in_line(line), end='')

    for file in files:
        os.rename(file, file.replace("placeholder", assignment_name))

# todo: trigger make on c and c++ folders

if __name__ == "__main__":
    main()