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

RUN useradd -ms /bin/bash dev \
  && mkdir -p /var/run/sshd /home/dev/.ssh \
  && chmod 700 /home/dev/.ssh \
  && chown -R dev:dev /home/dev/.ssh

RUN echo 'dev:dev' | chpasswd

RUN mkdir -p /app/CryptoHPC \
  && chown -R dev:dev /app

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
      libgl1-mesa-dev \
      libgtk-4-1 \
      libgtk-4-dev \
      gtk-4-examples \
      glibmm-2.68 \
      cairomm-1.16 \
      pangomm-2.48 \
      pkg-config \
      glib-2.0  \
      gdk-pixbuf-2.0 \
      graphene-1.0  \
      libgtkmm-4.0-dev \
      x11-apps \
  && apt-get clean
########################################################

CMD ["/usr/sbin/sshd", "-D"]