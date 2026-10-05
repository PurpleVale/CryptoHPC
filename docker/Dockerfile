FROM ubuntu:24.04

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    apt-utils gcc g++ openssh-server cmake build-essential gdb gdbserver rsync vim tzdata

RUN mkdir /var/run/sshd
RUN echo 'root:root' | chpasswd
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

EXPOSE 22

RUN useradd -ms /bin/bash dev
RUN echo 'dev:dev' | chpasswd

########################################################
# Add custom packages and development environment here
########################################################

RUN apt-get update \
  && apt-get install -y build-essential \
      gcc \
      g++ \
      gdb \
      clang \
      make \
      ninja-build \
      cmake \
      autoconf \
      automake \
      libtool \
      valgrind \
      locales-all \
      dos2unix \
      rsync \
      tar \
      python3 \
      libopenmpi-dev \
      openmpi-bin \
      libboost-all-dev \
      libfmt-dev \
  && apt-get clean
########################################################

CMD ["/usr/sbin/sshd", "-D"]