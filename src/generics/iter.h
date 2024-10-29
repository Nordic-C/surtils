#pragma once

#define FOREACH(type, collection, elem, action_block)                          \
  {                                                                            \
    for (size_t __iter_index__ = 0; __iter_index__ < collection.length;        \
         __iter_index__++) {                                                   \
      type elem = collection.data[__iter_index__];                             \
      action_block                                                             \
    }                                                                          \
  }

#define FOREACH_ENTRY(k_type, v_type, collection, key, value, action_block)    \
  for (size_t __iter_index__ = 0; __iter_index__ < collection.length;          \
       __iter_index__++) {                                                     \
    k_type key = collection.keys[__iter_index__];                              \
    v_type value = collection.values[__iter_index__];                          \
    action_block                                                               \
  }