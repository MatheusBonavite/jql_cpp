# JQL_CPP
A JSON Query Language CLI tool built with C++. Heavily inspired on [JQL](https://github.com/yamafaktory/jql).

# Core Philosophy
- Understand the C++ language better.
- Build a somehow useful tool.
- Generate reports based on JSON input.

# Non-goal
- Be efficiently competitive to its alternatives (like JQL).
- Work the same way as JQL or jq or any other CLI.

# Available Commands
- In the folder you have cloned the repo, you can do:

## To print the JSON file:
```bash
./jql_cpp print <YOUR JSON FILE NAME>

# Example:
./jql_cpp print file1.json
# Output:
{
    "name": "Matheus",
    "lastName": "Cardoso",
    "age": 25,
    "degree": {
        "level": "B.S",
        "field": "Engineering",
        "year": 2022
    }
}
```
## To describe the type of the fields:
```bash
./jql_cpp attributes <YOUR JSON FILE NAME>

# Example:
./jql_cpp attributes file1.json
# Output:
2:    name string
3:    lastName string
4:    age number
5:    degree object
6:        level string
7:        field string
8:        year number
```
# Testing with Docker
To use Docker to compile the code with g++ you can do (in the source folder of the repo):
```bash

docker build -t <YOUR IMAGE NAME> .

# Wait for the image to build... Might take some time (image is almost 1GB).
docker run -it <YOUR IMAGE NAME> bash

# After that, you should be in your image! Than do:
cd jql_cpp
./runner.sh #If you wanna run both the print and attributes commands

#Output:
{
    "name": "Matheus",
    "lastName": "Cardoso",
    "age": 25,
    "degree": {
        "level": "B.S",
        "field": "Engineering",
        "year": 2022
    }
}
2:    name string
3:    lastName string
4:    age number
5:    degree object
6:        level string
7:        field string
8:        year number
``` 
