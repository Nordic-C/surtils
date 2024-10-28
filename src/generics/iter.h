#define FOREACH(type, collection, elem, action_block) { \
 for (size_t i = 0; i < collection.length; i++) {\
    type elem = collection.data[i];\
    action_block\
 } \
}