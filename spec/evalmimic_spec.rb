require "evalmimic"

descrive EvalMimic, "evalmimic" do

  class X
  end

  it "should allow define of alternate eval using blocks" do
    X.define_eval_method :alternate_eval do |*args|
    end
  end

  class X2
    def internal_eval(code,binding,file,line)
    end
  end

  it "should allow define of alternate eval using internal methods" do
    X2.define_eval_method :alternate_eval, :internal_eval
  end

  class X3
  end

  it "should recall eval with default arguments" do
    X3.define_eval_method :alternate_eval do |args|
      args
    end

    x = X3.new

    args = x.alternate_eval "test"
    args[:args].should be == ["test"]

    a = 4
    args[:binding].eval("a").should be == 4

  end


end