#include "ruby.h"
#include <env.h>
#include <node.h>

ID id_to_s;
ID id_binding;

struct BLOCK {
    NODE *var;
    NODE *body;
    VALUE self;
    struct FRAME frame;
    struct SCOPE *scope;
    VALUE klass;
    NODE *cref;
    int iter;
    int vmode;
    int flags;
    int uniq;
    struct RVarmap *dyna_vars;
    VALUE orig_thread;
    VALUE wrapper;
    VALUE block_obj;
    struct BLOCK *outer;
    struct BLOCK *prev;
};


VALUE binding_recall(argc, argv, recv)
	int argc;
	VALUE* argv;
	VALUE recv;
{

	VALUE bind = rb_funcall(recv, id_binding,0);

	struct BLOCK* data;
	Data_Get_Struct(bind, struct BLOCK, data);

	// change the self of the binding to match the real self of the caller
	data->self = data->frame.prev->prev->self;

	return rb_funcall(recv, rb_intern("internal_eval"), 2, bind, rb_ary_new4(argc, argv) );
}

/* Define a new eval method in current class scope (see README and examples) */
VALUE define_eval_method(VALUE self, VALUE name) {


	VALUE str = rb_funcall(name, id_to_s, 0);
	rb_define_method(self, RSTRING(str)->ptr, binding_recall, -1);
	return Qnil;
}

/* Define a new global eval method (see README and examples) */
VALUE obj_define_eval_method(VALUE self, VALUE name) {


	VALUE str = rb_funcall(name, id_to_s, 0);
	rb_define_method(rb_cObject, RSTRING(str)->ptr, binding_recall, -1);
	return Qnil;
}


void Init_evalmimic_base() {
	id_to_s = rb_intern("to_s");
	id_binding = rb_intern("binding");

	/* Define a new eval method in current class scope (see README and examples) */
	rb_define_method(rb_cClass, "define_eval_method", define_eval_method, 1);
	/* Define a new global eval method (see README and examples) */
	rb_define_method(rb_cObject, "define_eval_method", obj_define_eval_method, 1);
}
