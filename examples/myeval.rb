require "rubygems"
require "evalmimic"

define_eval_method :my_eval

def internal_eval(b_, args)
	b_.eval("a+b")
end

def foo
	a = 4
	b = 5
	
	my_eval
end

print foo,"\n"