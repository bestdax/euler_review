tex.print("\\begin{tikzpicture}")
local function draw_rectangle(x, y, n, color)
    local command = string.format(
                        "\\draw [fill=%s!30] (%d, %d) rectangle node{%d} +(1, 1);",
                        color, x, y, n)
    tex.print(command)
end

for i = 1, 100 do
    local x = (i - 1) % 10
    local y = -((i - 1) // 10)
    local color = "red"
    if i == 1 then
        color = "gray"
    end

    draw_rectangle(x, y, i, color)

end

local status = {}
for _ = 1, 100 do
    table.insert(status, true)
end
local root = math.sqrt(100)
for i = 2, root do
    if status[i] then
        local times = 2
        while i * times <= 100 do
            status[i * times] = false
            local x1 = (i * times - 1) % 10
            local y1 = -((i * times - 1) // 10)
            draw_rectangle(x1, y1, i * times, "gray")
            times = times + 1
        end
    end
end
tex.print("\\end{tikzpicture}")
