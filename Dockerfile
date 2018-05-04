FROM ubuntu:18.04
RUN apt-get update -y
RUN apt-get install python-pip -y
RUN pip install flask peewee pylint
RUN apt-get install curl -y
RUN apt-get install vim -y
RUN apt-get install git -y
CMD bash
