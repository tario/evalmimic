require "evalmimic"

describe Evalmimic, "evalmimic" do

  class X
  end

  it "should allow define of alternate eval using blocks" do
    X.define_eval_method :alternate_eval
  end

  class X2
    def internal_eval(*args)
      args
    end
  end

  it "should allow define of alternate eval using internal methods" do
    X2.define_eval_method :alternate_eval
  end

  class X3
    def internal_eval(*args)
      args
    end
  end

  it "should recall eval with default arguments" do
    X3.define_eval_method :alternate_eval

    x = X3.new

    args = x.alternate_eval "test"
    args[1].should be == ["test"]

    a = 4
    args[0].eval("a").should be == 4

  end

   class N
    def foo(x)
      @a = 5
      args = x.alternate_eval "test"
      args[0].eval("@a")
    end
  end


  it "should recall eval with default arguments and eval local variables" do
    X3.define_eval_method :alternate_eval

    x = X3.new
    N.new.foo(x).should be == 5

  end

end