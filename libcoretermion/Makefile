NAME := "libcoretermion.a"

.SILENT: build clean fclean doc

default: build

build:
	cargo build --verbose && ln -svf ./target/debug/$(NAME) $(NAME) ;

build_jap:
	cargo build --features jap --verbose && ln -svf ./target/debug/$(NAME) $(NAME) ;

clean:
	cargo clean ;

fclean:
	cargo clean ;
	rm -vf Cargo.lock ;
	rm -vf $(NAME) ;

re: fclean build

doc:
	cargo doc --verbose ;
