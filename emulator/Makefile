
.PHONY: build
build: 
	mkdir -p build
	cmake -Bbuild -DCMAKE_BUILD_TYPE=Release
	cd build && make

.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -rf build

.PHONY: style
style:
	@echo "Running clang-format..."
	python scripts/style.py