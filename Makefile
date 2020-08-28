compile:
	@docker run --rm -v $(PWD):/usr/src/stack -w /usr/src/stack gcc gcc -o main main.cpp -lstdc++

run:
	@./main