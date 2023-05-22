#!/bin/bash

# Check if git is available
if ! which git >/dev/null; then
  echo "git not found. Please install git and try again." >&2
  exit 1
fi

# Check if the script is being run in a Git repository
if ! git rev-parse --show-toplevel >/dev/null 2>&1; then
  echo "This script must be run in a Git repository." >&2
  exit 1
fi

# Change the working directory to the root of the Git repository
cd "$(git rev-parse --show-toplevel)" || exit 1

# Create the header for the AUTHORS file
cat > AUTHORS <<EOH
# This file lists the authors that have contributed to this simple shell project.
EOH

# Retrieve list of all unique authors and append them to the AUTHORS file
git log --format='%aN <%aE>' | sort -uf >> AUTHORS || exit 1

# Count the number of authors
AUTHORS_COUNT=$(wc -l < AUTHORS | tr -d ' ')

# Display the result to the user
echo "AUTHORS file generated in $(pwd)/AUTHORS with $AUTHORS_COUNT authors."

