-- Configuracion de arranque para Lazy
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"

if not vim.loop.fs_stat(lazypath) then
	vim.fn.system({
		"git",
		"clone",
		"--filter=blob:none",
		"https://github.com/folke/lazy.nvim.git",
		"--branch=stable",
		lazypath,
	})
end
vim.opt.rtp:prepend(lazypath)

-- Instalamos los complementos para que Lazy.nvim funcione
require("lazy").setup({
  {
    -- Lsp para python
    "neovim/nvim-lspconfig",
    config = function()
      vim.lsp.config("pyright", {})
    end,
  },

    -- Autocompletado
  {
    "hrsh7th/nvim-cmp",
    dependencies = {
      "hrsh7th/cmp-nvim-lsp",  -- integración LSP + autocompletado
      "hrsh7th/cmp-buffer",    -- sugerencias del buffer actual
      "hrsh7th/cmp-path",      -- sugerencias de rutas
      "L3MON4D3/LuaSnip",      -- snippets
    },
  },


  {
    -- Tema tokyonight
    "folke/tokyonight.nvim",
    config = function()
      vim.opt.background = "dark"
      vim.g.tokyonight_transparent = true
      vim.cmd([[colorscheme tokyonight-storm]])
      vim.cmd([[
        hi Normal guibg=NONE ctermbg=NONE
        hi NormalNC guibg=NONE ctermbg=NONE
        hi SignColumn guibg=NONE ctermbg=NONE
        hi VertSplit guibg=NONE ctermbg=NONE
      ]])
    end,
  },


  {
  "lukas-reineke/indent-blankline.nvim",
  main = "ibl",
  opts = {
    -- Habilita el modo arcoíris para la alternancia de color
    scope = { enabled = true },
    -- Estilo de la línea guía de indentación (puedes usar '|', '¦', o '┊')
    indent = { char = "┊"},
    -- Configuración de los colores (usa los grupos de resaltado de Neovim)
    -- Por defecto, indent-blankline alternará los colores automáticamente
  },
  config = function(_, opts)
      require("ibl").setup(opts)
  end,
  }
  
})

-- Configuracion de autocompletado
vim.lsp.config("pyright", {
  capabilities = require("cmp_nvim_lsp").default_capabilities(),
  on_attach = function(client, bufnr)
  end,
})

-- Configuracion para Lua
vim.lsp.config("lua_ls", {
  settings = {
    Lua = {
      runtime = { version = "LuaJIT"},
      diagnostics = { globals = { "vim" }},
      workspace = {
        library = vim.api.nvim_get_runtime_file("", true),
        checkThridParty = false,
      },
      telemetry = { enable = false },
    }
  }
})

-- Configuracion para C / C++
vim.lsp.config("clangd", {
  capabilities = require("cmp_nvim_lsp").default_capabilities(),
})


local cmp = require("cmp")

cmp.setup({
  snippet = {
    expand = function(args)
      require("luasnip").lsp_expand(args.body)
    end,
  },
  mapping = cmp.mapping.preset.insert({
    ["<C-Space>"] = cmp.mapping.complete(),
    ["<CR>"] = cmp.mapping.confirm({ select = true }),
  }),
  sources = cmp.config.sources({
    { name = "nvim_lsp" },
    { name = "buffer" },
    { name = "path" },
  }),
})


-- Configuracion del log de Lsp
vim.lsp.set_log_level("warn")

-- Iniciamos los servers
vim.lsp.enable({
	"pyright", 
	"clangd" 
})

vim.opt.tabstop = 4         -- Number of spaces a tab character counts for
vim.opt.shiftwidth = 4      -- Number of spaces used for each step of (auto)indent
vim.opt.expandtab = true    -- Converts tabs to spaces
vim.opt.softtabstop = 4     -- Number of spaces to use when hitting <Tab> or <BS>



