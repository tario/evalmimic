#include "ruby.h"

ID id_to_s;
ID id_binding;

VALUE binding_recall(argc, argv, recv)
	int argc;
	VALUE* argv;
	VALUE recv;
{

	VALUE bind = rb_funcall(recv, id_binding,0);
	return rb_funcall(recv, rb_intern("internal_eval"), 2, bind, rb_ary_new4(argc, argv) );
}

VALUE define_eval_method(VALUE self, VALUE name) {


	VALUE str = rb_funcall(name, id_to_s, 0);
	rb_define_method(self, RSTRING(str)->ptr, binding_recall, -1);
	return Qnil;
}


void Init_evalmimic_base() {
	id_to_s = rb_intern("to_s");
	id_binding = rb_intern("binding");

	rb_define_method(rb_cClass, "define_eval_method", define_eval_method, 1);
}
