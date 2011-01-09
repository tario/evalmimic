$:.unshift(File.dirname(__FILE__)) unless
  $:.include?(File.dirname(__FILE__)) || $:.include?(File.expand_path(File.dirname(__FILE__)))

require "evalmimic_base"

module Evalmimic
  VERSION = '0.0.1'
end

class Class
  def define_eval_method

  end
end