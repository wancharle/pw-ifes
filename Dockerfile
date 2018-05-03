FROM ubuntu:18.04
RUN apt-get update -y
RUN apt-get install python-pip -y
RUN pip install flask peewee
RUN apt-get install firefox -y
RUN apt-get install curl -y
RUN curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg 
RUN mv microsoft.gpg /etc/apt/trusted.gpg.d/microsoft.gpg
RUN sh -c 'echo "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" > /etc/apt/sources.list.d/vscode.list'
RUN apt-get update -y
RUN apt-get install code -y
RUN useradd user && usermod -aG sudo user
RUN mkdir /home/user && chown -R user /home/user
RUN apt-get install aptitude -y
RUN apt-get install libxss1 -y
RUN apt-get update -y
RUN apt-get install libgtkextra-dev -y
RUN apt-get install vim -y
RUN apt-get install git -y
RUN sed -i 's/BIG-REQUESTS/_IG-REQUESTS/' /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0
RUN sed -i 's/BIG-REQUESTS/_IG-REQUESTS/' /usr/lib/x86_64-linux-gnu/libxcb.so.1
RUN apt-get install sudo -y
RUN echo "ALL            ALL = (ALL) NOPASSWD: ALL" >>/etc/sudoers
RUN pip install pylint

WORKDIR /home/user
USER user
code --install-extension ms-python.python
CMD bash
