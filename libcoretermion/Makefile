NAME := "libcoretermion.a"

.SILENT: build clean fclean doc

default: build

build:
	cargo build --verbose && ln -svf ./target/debug/$(NAME) $(NAME) ;

clean:
	cargo clean ;

fclean: clean
	rm -vf $(NAME) ;

re: fclean build

doc:
	cargo doc --verbose ;
