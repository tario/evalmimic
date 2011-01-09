require "rubygems"
require "evalmimic"

alias original_eval eval
define_eval_method :eval

def internal_eval(b_, args)
	print "eval called with code = #{args[0].inspect}\n"
	
	args[1] = args[1] || b_
	
	original_eval(*args)
end

def foo
	a = 4
	eval "a"
end

print foo,"\n"