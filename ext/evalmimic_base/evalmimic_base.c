#include "ruby.h"

VALUE binding_recall(argc, argv, recv)
	int argc;
	VALUE* argv;
	VALUE recv;
{

	VALUE bind = rb_funcall(recv, rb_intern("binding"),0);
	return rb_funcall(recv, rb_intern("internal_eval"), 2, bind, rb_ary_new4(argc, argv) );
}

VALUE define_eval_method(VALUE self, VALUE name) {


	VALUE str = rb_funcall(name, rb_intern("to_s"), 0);
	rb_define_method(self, RSTRING(str)->ptr, binding_recall, -1);
	return Qnil;
}


void Init_evalmimic_base() {
	rb_define_method(rb_cClass, "define_eval_method", define_eval_method, 1);
}
