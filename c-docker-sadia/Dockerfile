FROM gcc:latest 
#base image, from dockerhub. gcc
WORKDIR /app

COPY . /app

RUN gcc -o output-app main.c

CMD ["./output-app"] 
