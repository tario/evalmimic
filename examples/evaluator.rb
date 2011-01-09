require "rubygems"
require "evalmimic"

class MyEvaluator
	define_eval_method :eval

	def internal_eval(b_, args)
		b_.eval(args[0])
	end
	
end

def foo
	m = MyEvaluator.new
	
	a = 4
	b = 5
	
	m.eval "a+b"
	
end

print foo,"\n"