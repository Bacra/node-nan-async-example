{
  "targets": [
    {
      "target_name": "async",
      "sources": [ "async.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
