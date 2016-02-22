nan async example  [![Build Status](https://travis-ci.org/Bacra/node-nan-async-example.svg?branch=master)](https://travis-ci.org/Bacra/node-nan-async-example)
==================

# Install
```
npm install nan-async-example
```

# Useage

```
var NanAsync = require('nan-async-example');
var assert = require('assert');

NanAsync(function(err, data)
{
	assert(!err);
	assert.equal(data, 'hell world')
});
```
