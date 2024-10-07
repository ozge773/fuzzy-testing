cnf ?= Makefile.env
include $(cnf)
cnfe ?= ../Makefile.env 
-include $(cnfe)

ifeq ($(OS), Windows_NT)
	CATCH=2>NUL || VER>NUL
else
	CATCH=2>/dev/null ; true
endif

build:  
	-docker build --no-cache -f Dockerfile -t $(IMAGE_NAME):$(IMAGE_TAG) "$(CURDIR)"
			
run:
	-docker start $(CONTAINER_NAME) $(CATCH)
	-docker run -d --name $(CONTAINER_NAME) --memory="16g" --memory-swap="64g"  -v"$(HOST_PATH_VSPACE_HOST):$(CONTAINER_PATH_VSPACE)" -h "fuzz-test-core" $(IMAGE_NAME):$(IMAGE_TAG) $(CATCH)
	
connect:
	-docker exec -w /home -it $(CONTAINER_NAME) /bin/bash $(CATCH)
	
stop:
	-docker kill $(CONTAINER_NAME) $(CATCH)

remove:	
	-docker rm $(CONTAINER_NAME) $(CATCH)

discard:
	-docker kill $(CONTAINER_NAME) $(CATCH)
	-docker rm $(CONTAINER_NAME) $(CATCH)
	
delete:
	-docker image rm $(CONTAINER_NAME):$(IMAGE_TAG) $(CATCH)
