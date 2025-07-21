import tkinter as tk

class GridEnvironment(tk.Tk):
    def init(self, grid_size=8, cell_size=60):
        super().init()
        self.grid_size = grid_size
        self.cell_size = cell_size
        self.title("محیط گرافیکی عامل")
        
        self.canvas = tk.Canvas(self, width=grid_size*cell_size, height=grid_size*cell_size)
        self.canvas.pack()

        self.agent_pos = (0, 0)  # موقعیت اولیه عامل
        self.draw_grid()
        self.draw_agent()

    def draw_grid(self):
        """ رسم محیط شبکه‌ای """
        for i in range(self.grid_size):
            for j in range(self.grid_size):
                x1 = i * self.cell_size
                y1 = j * self.cell_size
                x2 = x1 + self.cell_size
                y2 = y1 + self.cell_size
                self.canvas.create_rectangle(x1, y1, x2, y2, outline="gray")

    def draw_agent(self):
        """ رسم عامل به شکل دایره آبی """
        x, y = self.agent_pos
        cx = x * self.cell_size + self.cell_size // 2
        cy = y * self.cell_size + self.cell_size // 2
        r = self.cell_size // 3
        self.agent = self.canvas.create_oval(cx - r, cy - r, cx + r, cy + r, fill="blue")

    def move_agent(self, dx, dy):
        """ انتقال عامل در محیط و به‌روزرسانی نمایش """
        new_x = self.agent_pos[0] + dx
        new_y = self.agent_pos[1] + dy

        if 0 <= new_x < self.grid_size and 0 <= new_y < self.grid_size:
            # فاصله بصری برای حرکت روی Canvas
            x_offset = dx * self.cell_size
            y_offset = dy * self.cell_size

            self.canvas.move(self.agent, x_offset, y_offset)
            self.agent_pos = (new_x, new_y)

if name == "main":
    env = GridEnvironment()

    # حرکت‌های آزمایشی برای عامل
    env.after(1000, lambda: env.move_agent(1, 0))  # حرکت به راست
    env.after(2000, lambda: env.move_agent(0, 1))  # حرکت به پایین
    env.after(3000, lambda: env.move_agent(1, 0))  # دوباره به راست

    env.mainloop()
