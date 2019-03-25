-- 当你通过键来访问 table 的时候，如果这个键没有值，那么Lua就会寻找该table的metatable
mytable = setmetatable({key1 = "value1"}, {
  __index = function(mytable, key)
    if key == "key2" then
      return "metatablevalue"
    else
      return nil
    end
  end
})

print(mytable.key1,mytable.key2)
