.PHONY: build run clean test

# The default target of this Makefile is build which builds the project.
default: build

# to compile the project, type 'make build'
build:
	cargo build
# to compile the project in release mode, type 'make release'
release:
	cargo build --release

# To run the project, type 'make run'
run: build
	cargo run

# To clean the project, type 'make clean'
clean:
	cargo clean

# To test the project, type 'make test'
test:
	cargo test
# To generate a .gitignore file, type 'make gitignore'
gitignore:
	echo target >> .gitignore
	echo Cargo.lock >> .gitignore