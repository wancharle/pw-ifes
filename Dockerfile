
FROM ubuntu:18.04

RUN apt update -y
RUN apt install python-pip -y
RUN pip install flask peewee

workdir /root/
CMD bash
