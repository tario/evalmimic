require 'rubygems'
require 'rake'
require 'rake/testtask'
require 'rake/rdoctask'
require 'rake/gempackagetask'

spec = Gem::Specification.new do |s|
  s.name = 'evalmimic'
  s.version = '0.1.0'
  s.author = 'Dario Seminara'
  s.email = 'darios_3@gmail.com'
  s.platform = Gem::Platform::RUBY
  s.summary = 'Evalmimic allow the implementation of eval like methods, solves the common problem of binding retrieve: in ruby you can\'t obtain the binding of the caller, or if you can, is some tricky'
  s.homepage = "http://github.com/tario/evalmimic"
  s.has_rdoc = true
  s.extra_rdoc_files = [ 'README' ]
  s.rdoc_options << '--main' << 'README'
  s.extensions = FileList["ext/**/extconf.rb"].to_a
  s.files = Dir.glob("{examples,lib,test}/**/*.rb") + Dir.glob("ext/**/*.c") + Dir.glob("ext/**/*.h") + Dir.glob("ext/**/extconf.rb") +
    [ 'AUTHORS', 'CHANGELOG', 'README', 'Rakefile', 'TODO', 'LICENSE' ]
end

desc 'Run tests'
task :default => [ :test ]

Rake::TestTask.new('test') do |t|
  t.libs << 'test'
  t.pattern = '{test}/**/test_*.rb'
  t.verbose = true
end

desc 'Generate RDoc'
Rake::RDocTask.new :rdoc do |rd|
  rd.rdoc_dir = 'doc'
  rd.rdoc_files.add 'lib', 'ext', 'README'
  rd.main = 'README'
end

desc 'Build Gem'
Rake::GemPackageTask.new spec do |pkg|
  pkg.need_tar = true
end

desc 'Clean up'
task :clean => [ :clobber_rdoc, :clobber_package ]

desc 'Clean up'
task :clobber => [ :clean ]
