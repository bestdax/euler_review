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
local primes = {}
for i = 2, 100 do
    if status[i] then
        table.insert(primes, i)
    end

    for _, p in ipairs(primes) do
        if i * p <= 100 then
            status[i * p] = false
            local x1 = (i * p - 1) % 10
            local y1 = -((i * p - 1) // 10)
            draw_rectangle(x1, y1, i * p, "gray")
        else
            break
        end

        if i % p == 0 then
            break
        end
    end

    draw_rectangle(12, -5, i, "blue")
end

for i, p in ipairs(primes) do
    local x2 = (i - 1) % 10
    local y2 = -((i - 1) // 10)
    draw_rectangle(x2, -11 + y2, p, "green")
end
tex.print("\\end{tikzpicture}")
