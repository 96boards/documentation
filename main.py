import os
import os.path

exclusions = ["/README.md","./CONTRIBUTE.md", "./LICENSE.md",
              "./Extras/Report_a_bug.md", "./Extras/CrossCompile/CommandLine.md", "./Extras/CrossCompile/EclipseIDE.md"]

for dirpath, dirnames, filenames in os.walk("."):
    for filename in filenames:
        if filename.endswith(".md") and os.path.join(dirpath, filename) not in exclusions and "README.md" not in filename:
            # Path to original file
            file_path = os.path.join(dirpath, filename)
            # New folder
            file_path_without_extension = os.path.splitext(file_path)[0]
            # print(os.path.join(dirpath, filename))
            print("Creating directory for {0}".format(file_path_without_extension))
            os.mkdir(file_path_without_extension)
            print("Moving {0} to it's new home - {1}".format(filename, file_path_without_extension + "/"))
            os.rename(file_path, file_path_without_extension + "/README.md")
