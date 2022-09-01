FROM ubuntu:latest
RUN apt-get update
RUN apt-get install vim -y
RUN apt-get install git -y
RUN apt-get install g++-12 -y
RUN git clone "https://github.com/MatheusBonavite/jql_cpp.git"
WORKDIR /jql_cpp
ENTRYPOINT [ "bash" ]